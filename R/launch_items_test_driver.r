library(RUnit)

source("launch_items_wrangle.r")


cmd.args <- commandArgs(trailingOnly = TRUE)
test.dir <- "tests"


test.suite.launch.items.door.busters <- defineTestSuite("Launch Items Door Busters Metrics Test Suite",
                                                        dirs=test.dir,
                                                        testFileRegexp = '^launch_items_doorbusters*.+\\.R')

test.suite.launch.items.status <- defineTestSuite("Launch Items Past Launch Metrics Test Suite",
                                                       dirs=test.dir,
                                                       testFileRegexp = '^launch_items_status*.+\\.R')

launch.items.suites <- list(test.suite.launch.items.door.busters, test.suite.launch.items.status)

test.result <- runTestSuite(launch.items.suites)

printTextProtocol(test.result)
