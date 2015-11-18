library(dplyr)

#Mac
setwd("~/git/Demos/R")

#Vector Operations
## Add 3
one.thru.five <- seq(1,5)
four.thru.eight <- one.thru.five + 3
four.thru.eight
print(four.thru.eight)

## custom function
add3 <- function(my.vector) {
    my.vector + 3
}
four.thru.eight.2 <- add3(one.thru.five)

add.number.to.vector <- function(my.vector, number.to.add) {
    my.vector + number.to.add
}
four.thru.eight.3 <- add.number.to.vector(one.thru.five, 5)

#Read from CSV
used.cars.csv <- "used_cars.csv"
read.csv(used.cars.csv)
used.cars <- read.csv(used.cars.csv)
str(used.cars)
levels(used.cars$MAKE)
names(used.cars)

#Make, model, interior color, and exterior color are factors
levels(used.cars$make) #OOPS Case sensitive
levels(used.cars$MAKE)
used.cars[used.cars$MAKE=="Honda",]
used.cars[used.cars$YEAR>2009, c("ID", "MAKE", "MODEL", "MILES")]

#Headers

used.cars.no.headers  #OOPS, the headers are in the first row now
used.cars.no.headers.csv <- "used_cars_no_headers.csv"
used.cars.no.headers <- read.csv(used.cars.no.headers.csv)
used.cars.no.headers  #OOPS, the first column appears as the header!
used.cars.no.headers <- read.csv(used.cars.no.headers.csv, header=FALSE)
used.cars.no.headers
names(used.cars.no.headers)
str(used.cars.no.headers)

#Column names
names(used.cars.no.headers)  <- c("id", "make", "model", "year", "interior color", "exteriror color", "miles")
names(used.cars.no.headers)
str(used.cars.no.headers)

#change all column names to lower
names(used.cars)
names(used.cars) <- sapply(names(used.cars), FUN=tolower)
?sapply
names(used.cars)

#Read from html (website)
library(XML)
espn.qb <- readHTMLTable("http://games.espn.go.com/ffl/tools/projections?&slotCategoryId=0&startIndex=0", skip=1)
espn.qb <- espn.qb$playertable_0
head(espn.qb)
str(espn.qb)

espn.rb <- readHTMLTable("http://games.espn.go.com/ffl/tools/projections?&slotCategoryId=2&startIndex=0", skip.rows=1)$playertable_0
dim(espn.rb)
str(espn.rb)
dim(espn.rb)[1]
espn.rb <- rbind(espn.rb,readHTMLTable("http://games.espn.go.com/ffl/tools/projections?&slotCategoryId=2&startIndex=40", skip.rows=1)$playertable_0)
dim(espn.rb)
dim(espn.rb)[1]

#Write to csv
written.csv <- "auto.written1.csv"
write.csv(used.cars, written.csv)
dim(used.cars)
dim(read.csv(written.csv))
write.csv(read.csv(written.csv), "auto.written2.csv")
dim(read.csv("auto.written2.csv"))
read.csv("auto.written2.csv")


#Read another csv
used.cars.accidents <- read.csv("used_cars_accidents.csv")
used.cars.accidents
str(used.cars.accidents)

?left_join
used.cars.all <- left_join(used.cars, used.cars.accidents, by="ID")  ## OOPS
used.cars.all <- left_join(used.cars, used.cars.accidents, by=c("id" = "ID"))
str(used.cars.all)
used.cars.all

sum(used.cars.all$ACCIDENTS)

length(used.cars.all$ACCIDENTS[ is.na(used.cars.all$ACCIDENTS) ])

#Convert the NAs to 0?
used.cars.all <- used.cars.all %>% mutate(new.accidents = ifelse(is.na(ACCIDENTS), NA, ACCIDENTS))
used.cars.all

#What if I want to just replace the ACCIDENTS column in place?
used.cars.all <- used.cars.all %>% select(-new.accidents) %>% mutate(ACCIDENTS = ifelse(is.na(ACCIDENTS), 0, ACCIDENTS))
used.cars.all
## Remove the unused column
used.cars.all <- used.cars.all %>% select(-new.accidents)
used.cars.all
#I only want to see the VIN, miles, ACCIDENTS, year
used.cars.all %>% select(VIN, miles, ACCIDENTS, year)
used.cars.all %>% select(-(1:4))
#I want to see the average number of miles of cars, by year
used.cars.all %>% group_by(year) %>% summarise(mean(miles))

#I want to see the average number of miles of cars, by year
used.cars.all %>% group_by(year) %>% summarise(mean(miles))

# What about querying a database?
library(RMySQL)
items.past.launch.query <- "PUT YOUR QUERY HERE"

# Runs a query against MSWB and returns the dataframe
load.mswb.query <- function(query, mswb.pwd) {
    mydb <- dbConnect(MySQL(), user='******', password=mswb.pwd, dbname='*****', host='*******')
    data <- dbGetQuery(mydb, query)
    dbDisconnect(mydb)
    data
}

#retrieves the items past launch data from MySQL (MSWB Server)
items.past.launch.get.data <- function(mswb.pwd)
{
    load.mswb.query(items.past.launch.query, mswb.pwd)
}

items.past.launch.results <- items.past.launch.get.data(mswb.pwd)
str(items.past.launch.results)
head(items.past.launch.results)
#rm(items.past.launch.results)
