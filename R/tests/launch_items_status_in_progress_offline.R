library(RUnit)
library(dplyr)

in.progress <- "In Progress"

test.launch.items.in.progress.online <- function() {
    
    items.in.progress.online <- data.frame(status = rep(in.progress, 3), is.online = c(1,1,1))
    new.column <- get.metric.active.offline(items.in.progress.online)
    
    checkEquals(3, length(new.column))
    checkEquals(rep(0,3), new.column)
}

test.launch.items.in.progress.offline <- function() {
    
    items.in.progress.offline <- data.frame(status = rep(in.progress, 3), is.online = rep(0,3))
    new.column <- get.metric.active.offline(items.in.progress.offline)
    
    checkEquals(3, length(new.column))
    checkEquals(rep(0,3), new.column)
}

test.launch.items.in.progress.mixed <- function() {
    
    items.in.progress.mixed <- data.frame(status = rep(in.progress, 3), is.online = c(1,1,0))
    new.column <- get.metric.active.offline(items.in.progress.mixed)
    
    checkEquals(3, length(new.column))
    checkEquals(c(0,0,0), new.column)
}

test.launch.items.in.progress.case.sensitive <- function() {
    
    items.in.progress.mixed.case <- data.frame(status = c(in.progress, "in Progress", in.progress), is.online = c(1,1,0))
    new.column <- get.metric.active.offline(items.in.progress.mixed.case)
    
    checkEquals(3, length(new.column))
    checkEquals(c(0,0,0), new.column)
}