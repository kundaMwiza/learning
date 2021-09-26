Loosely speaking, Eigen has two types, **Expressions** and **Objects**.

Eigen uses expression templates for lazy evaluation. In Eigen, _most_ of the time expressions are only evaluated into rvalues when they are on the right hand side of an assignment operator.

Examples of expressions include:

```c++
#include <Eigen\Dense>

Eigen::MatrixXd mat, mat1, mat2;

// expression
mat1 + mat2;

// mat1 + mat2 only evaluated once _directly_ into the destination object
// rather than as usual to first evaluate mat1 + mat2 into a temporary, then copy
// the temporary into mat
mat = mat1 + mat2;

// for some expressions, like those involving operator*, Eigen _has_ to evaluate
// the expression into a temporary first for correctness, e.g. mat1 = mat1 * mat2;
// this is because for matrix multiplication, the same row/col is reused
// so if we are writing/overwriting directly into the destination object
// once some values are updated, subsequent calculations will be wrong
// since of course, to implement a matrix multiplication we need a for loop
// this is what is called aliasing in Eigen
mat1 = mat1 * mat2;

// Another example of alising:
// once the first col is transposed as a row
// the other columns are no longer correct..
mat1 = mat1.transpose();

// to explicitly request Eigen to evaluate the expression into
// a temporary, use .eval() on the expression:
mat1 = mat1.transpose().eval();

// when we know no aliasing will occur, use .noalias() on the destination object
// Eigen by default will write mat * mat1 into a temporary
mat2.noalias() = mat * mat1;
```

If Eigen is not returning an expression, it is either returning void or a reference to elements in the Matrix/ Array/ Object. For example, `mat1 * mat2;` above is an expression. Whereas `mat1.col(ind)` returns an object that contains a reference to the index referred to by ind. For the latter case, this means we can do things like:

```c++

// assign directly into the view of the object being
// referred to
const std::size_t ind(0);
mat1.col(ind) += Eigen::MatriXd::Random(3, 1);

// copy the view that is being referred to
Eigen::MatrixXd col_copy = mat1.col(ind);

// col is a block expression
// block expressions can be used as lvalues
// and rvalues in Eigen
// but in order to create a reference to a
// block we shuold use the Eigen::Ref<MatrixXd> class
// rather than (wont compile):
Eigen::MatrixXd &col_ref = mat1.col(ind);
// will compile, above wont
Eigen::Ref<Eigen::MatrixXd> col_ref = mat1.col(ind);
```

Due to the fact that Eigen either uses expressions or specific types e.g.
MatrixXd, when defining variables, we shouldn't use `auto`, for the type
of the object may either be an expression, or it may be an object. In the case of when it is an expression, this means whenever the variable is used thereafter, the expression will be evaluated repeatedly.. For example:

```c++
// Eigen deduced mat1 as an expression
auto mat1 = mat2 + mat;

// redundant for loop
for (auto i = 0; i != 5; ++i) {
    // expression mat1 evaluated each iteration of the loop..
    mat *= mat1;
}
```

In particular, this means that we should not use the `auto` type deducer for C++11.

Additionally, to avoid many copies, typically functions taking Eigen objects should be passed by reference, rather than by value, to avoid copy constructing temporaries from either references or specific object types e.g. Matrix or Array.

```c++
// good
void foo(const Eigen::MatrixXd &mat);

// not great
void foo(Eigen::MatrixXd mat);

```
