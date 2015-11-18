library(dplyr)

#SOLID
launch.items <- read.csv("random_sheet.csv")
dim(launch.items)
str(launch.items)

# add a metric that tells if an item is a door buster but out of stock
doorbusters.out.of.stock <- launch.items %>% mutate(db.oos = (door.buster == 1 && in.stock == 0))
str(doorbusters.out.of.stock)
length(doorbusters.out.of.stock[doorbusters.out.of.stock$db.oos==1,"db.oos"]) #40000?  That's odd

doorbusters.out.of.stock <- launch.items %>% mutate(db.oos = ifelse(door.buster == 1 && in.stock == 0, 1, 0))
length(doorbusters.out.of.stock[doorbusters.out.of.stock$db.oos==1,"db.oos"]) #40000?  That's odd

doorbusters.out.of.stock <- launch.items %>% mutate(db.oos = ifelse( door.buster == 1 & in.stock == 0, 1, 0))

doorbusters.out.of.stock <- launch.items %>% mutate(db.oos = get.metric.door.buster.offline(launch.items))
length(doorbusters.out.of.stock[doorbusters.out.of.stock$db.oos==1,"db.oos"])


### THAT WAS ALL WAY TOO HARD TO FIGURE OUT  ###
### WITH 40,000 RECORDS, HOW CAN I VERIFY THEM ALL?? ###

## Using Test-Driven Development (TDD) with SMALL functions, I can test first, then integrate with confidence ##
#Test files
 # launch_items_doorbusters_out_of_stock.R
 # launch_items_status_in_progress_offline.R
 # launch_items_status_offline.R

#Create separate files with specific features
 # launch_items_wrangle.r
   # contains functions that I will integrate into this code to make it easy to add the columns
source("launch_items_wrangle.r")
launch.items.with.metrics <- launch.items %>% mutate(db.oos = get.metric.door.buster.out.of.stock(launch.items)) %>%
                                              mutate(active.offline = get.metric.active.offline(launch.items)) %>%
                                              select(id, door.buster, in.stock, db.oos, status, is.online, active.offline)








