library(RUnit)
#install.packages("compare")
library(compare)

test.doorbuster.out.of.stock.1 <- function()
{
    data.doorbusters.offline <- data.frame(door.buster = c(1, 1, 1), in.stock = c(0, 0, 0))
    new.column <- get.metric.door.buster.out.of.stock(data.doorbusters.offline)
    
    checkEquals(3, length(new.column))
    checkEquals(rep(1, 3), new.column)
}

test.doorbuster.out.of.stock.0 <- function() {
    
    data.doorbusters.online <- data.frame(door.buster = c(1,1,1, 1), in.stock = c(1,1,1, 1))
    new.column <- get.metric.door.buster.out.of.stock(data.doorbusters.online)
    
    checkEquals(4, length(new.column))
    checkEquals(rep(0,4), new.column)
}

test.doorbuster.out.of.stock.mix <- function() {
    
    data.doorbusters <- data.frame(door.buster = c(1,1,1), in.stock = c(1,0,0))
    new.column <- get.metric.door.buster.out.of.stock(data.doorbusters)
    
    checkEquals(3, length(new.column))
    checkEquals(c(0,1,1), new.column)
}