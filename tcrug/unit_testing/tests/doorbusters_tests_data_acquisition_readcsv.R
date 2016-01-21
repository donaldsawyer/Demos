#?defineTestSuite

doorbusters.names.in.csv <- c("id", "door buster", "in stock", "is online", "launch date", "has image",
                              "status code", "status", "Has Price", "Price")

doorbusters.names <- c("id", "door.buster", "in.stock", "is.online", "launch.date", "has.image",
                       "status.code", "status", "Has.Price", "Price")

# test that the read.doorbuster.csv() function works as expected #
test.read.doorbuster.csv_read.proper.format <- function()
{
}

# test that the read.all.doorbuster.files() function reads both csv files#
test.read.all.doorbuster.files_exactly.two <- function()
{
}

# test that the read.all.doorbuster.files() function reads ONLY the two csv files#
test.read.all.doorbuster.files_three.files <- function()
{
}

#test that missing doorbuster*.csv files are handled properly #
## Design the behavior
## Write the test
## fix the function