library(RUnit)
library(dplyr)

test.launch.items.active.online <- function() {
    
    items.active.online <- data.frame(status = c("Active", "Active", "Active"), is.online = c(1,1,1))
    new.column <- get.metric.active.offline(items.active.online)
    
    checkEquals(3, length(new.column))
    checkEquals(rep(0,3), new.column)
}

test.launch.items.active.offline <- function() {
    
    active <- "Active"
    items.active.offline <- data.frame(status = rep(active, 3), is.online = rep(0,3))
    new.column <- get.metric.active.offline(items.active.offline)
    
    checkEquals(3, length(new.column))
    checkEquals(rep(1,3), new.column)
}

test.launch.items.active.mixed <- function() {
    
    active <- "Active"
    items.active.mixed <- data.frame(status = rep(active, 3), is.online = c(1,1,0))
    new.column <- get.metric.active.offline(items.active.mixed)
    
    checkEquals(3, length(new.column))
    checkEquals(c(0,0,1), new.column)
}

test.launch.items.active.case.sensitive <- function() {
    
    active <- "Active"
    items.active.mixed.case <- data.frame(status = c(active, "active", active), is.online = c(1,1,0))
    new.column <- get.metric.active.offline(items.active.mixed.case)
    
    checkEquals(3, length(new.column))
    checkEquals(c(0,0,1), new.column)
}