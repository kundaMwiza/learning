#get
# source("mwiza_DM_02_03.R", chdir = T)
# dirname(parent.frame(2)$ofile)
# Check if pacman is installed; if not, install it

# if (!require("packman")) install.packages("pacman")

library(pacman)
p_load(psych) # load the psych package
p_depends(psych)
p_load(GPArotation)


# LOAD DATA

b5 <- read.csv("./data/b5.csv", header = TRUE)
boxplot(b5)

# PCA

# First PCA with 5 components
pc0 <- principal(b5, nfactors = 5)
pc0 # check results

# Second PCA with oblimin (oblique) rotation

pc1 <- principal(b5, nfactors = 5, rotate = "oblimin")
pc1

# INSPECT RESULTS

plot(pc1)

# CLEAR UP 

rm(list = ls())


