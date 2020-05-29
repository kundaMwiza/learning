import tensorflow as tf
import numpy as np
from matplotlib import pyplot as plt

def createBatches(train, labels, n=1000):
    l = len(train)
    for ndx in range(0, l, n):
        yield train[ndx:min(ndx+n, l)], labels[ndx:min(ndx+n, l)]
        
def MNISTclassification():
    x = tf.placeholder(tf.float32, shape=[None, ftSize], name ='x')
    y = tf.placeholder(tf.float32, shape=[None, nDigits], name='y')
    with tf.variable_scope('zheng') as scope:
        weightsOne = tf.Variable(np.random.normal(size=(ftSize, 300)), name='weightsOne', dtype=tf.float32)
        h1 = tf.nn.relu(tf.matmul(x, weightsOne))
        weightsTwo = tf.Variable(np.random.normal(size=(300, 10)), name='weightsTwo', dtype=tf.float32)
        h2 = tf.matmul(h1, weightsTwo)
        loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=h2, labels=y))
        correctPrediction = tf.equal(tf.argmax(h2, 1), tf.argmax(y, 1))
        totalCorrect = tf.reduce_sum(tf.cast(correctPrediction, tf.float32))

    return loss, x, y, totalCorrect, h2

def run(xTrain, yTrain):
    loss, x, y, correctPreds, preds = MNISTclassification()
    optimizer = tf.train.GradientDescentOptimizer(0.0001).minimize(loss)
    init = tf.global_variables_initializer
    trainLosses = []
    testLosses=[]
    with tf.Session() as sess:
        sess.run(init())
        # train for 10  epochs, mini-batches of 1000
        for i in range(10):
            inds = np.random.choice(list(range(0, nTrain)), size=nTrain, replace=False)
            xTrain = xTrain[inds]
            yTrain = yTrain[inds]
            # forward pass
            print('-'*100)
            print('epoch:', i+1)
            for xBatch, yBatch in createBatches(xTrain, yTrain):
                feedDict = {x: xBatch, y: yBatch}
                sess.run([loss, optimizer], feedDict)
            # compute training loss and accuracy
            feedDict = {x: xTrain, y: yTrain}
            lossVal, nCorrect = sess.run([loss, correctPreds], feedDict)
            trainLosses.append(lossVal)
            print('loss on training set:', lossVal)
            print('accuracy on training set:', (nCorrect/nTrain)*100)
            # compute test loss and accuracy
            feedDict = {x: xTest, y: yTest}
            lossVal, nCorrect = sess.run([loss, correctPreds], feedDict)
            testLosses.append(lossVal)
            print('-'*100)
        # plot loss wrt epoch
        plt.plot(list(range(10)), trainLosses, color='r')
        plt.plot(list(range(10)), testLosses, color='b')
        plt.savefig('plot.png')
        # compute test accuracy
        feedDict = {x: xTest, y: yTest}
        nCorrect, testPreds = sess.run([correctPreds, preds], feedDict)
        print('accuracy on test set:', (nCorrect/nTest)*100)
    return testPreds
            
        
if __name__ == '__main__':
    (xTrain, yTrain), (xTest, yTest) = tf.keras.datasets.mnist.load_data()
    nTrain = xTrain.shape[0]
    nTest = xTest.shape[0]
    nDigits = np.unique(yTrain).shape[0]
    xTrain = xTrain.reshape(nTrain, 28*28)
    xTest = xTest.reshape(nTest, 28*28)
    yTrainTemp = np.zeros((nTrain, nDigits))
    yTestTemp = np.zeros((nTest, nDigits))
    yTrainTemp[np.arange(nTrain), yTrain] = 1
    yTestTemp[np.arange(nTest), yTest] = 1
    yTrain = yTrainTemp
    yTest = yTestTemp
    ftSize = xTrain.shape[-1]
    testPred = run(xTrain, yTrain)
        
    
    


