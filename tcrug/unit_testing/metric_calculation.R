library(dplyr)

add.column.db.noprice <- function(doorbusters.data)
{
    doorbusters.data <- doorbusters.data %>% 
        mutate(db.no.price = ifelse(door.buster == 1 & Price == 0, "1", "0"))
    
    doorbusters.data
}

add.column.db.online.outofstock <- function(doorbusters.data)
{
    doorbusters.data <- doorbusters.data %>% 
        mutate(db.online.nostock = door.buster == 1 & is.online == 1 & in.stock == 0)
    
    doorbusters.data
}
