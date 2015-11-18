library(dplyr)

get.metric.door.buster.out.of.stock <- function(launch.items) {
    ifelse( launch.items$door.buster == 1 & launch.items$in.stock == 0, 1, 0)
}

get.metric.active.offline <- function(launch.items) {
    
    ifelse( launch.items$status == "Active" & launch.items$is.online == 0, 1, 0)
}