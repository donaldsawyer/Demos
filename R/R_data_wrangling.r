library(dplyr)

setwd("c:\\ds\\git\\demos\\r")

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

add3(one.thru.five)

add.number.to.vector <- function(my.vector, number.to.add) {
    my.vector + number.to.add
}

add.number.to.vector(one.thru.five, 3)


#Read from CSV
used.cars.csv <- "used_cars.csv"
read.csv(used.cars.csv)
used.cars <- read.csv(used.cars.csv)
str(used.cars)
names(used.cars)

#Make, model, interior color, and exterior color are factors
levels(used.cars$make) #OOPS Case sensitive
levels(used.cars$MAKE)
used.cars[used.cars$MAKE=="Honda",]
used.cars[used.cars$YEAR>2009, c("ID", "MAKE", "MODEL", "MILES")]

#Headers
used.cars.no.headers <- read.csv(used.cars.csv, header=FALSE)
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
dim(espn.rb)[1]
espn.rb <- rbind(espn.rb,readHTMLTable("http://games.espn.go.com/ffl/tools/projections?&slotCategoryId=2&startIndex=40", skip.rows=1)$playertable_0)
dim(espn.rb)
dim(espn.rb)[1]

#Write to csv

#Read another csv

#Analyze data
#BAD DATA


#join data

#mutate data


#SOLID
#Functions

#TDD

# Test Driver


#BONUS
#Built-in Dataset (iris)
#Built-in Dataset (mtcars)