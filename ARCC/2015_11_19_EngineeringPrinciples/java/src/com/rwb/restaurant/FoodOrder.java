package com.rwb.restaurant;

import com.rwb.strategies.IOrder;
import com.rwb.strategies.MenuItem;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Donald on 11/18/2015.
 */
public class FoodOrder implements IOrder
{
    private List<MenuItem> menuItems = new ArrayList<MenuItem>();

    @Override
    public double calculateTotal()
    {
        double totalAmount = 0.0;

        for(MenuItem menuItem : menuItems)
        {
            totalAmount += menuItem.getPrice() + menuItem.calculateTax();
        }

        return totalAmount;
    }

    @Override
    public void addMenuItem(MenuItem item)
    {
        menuItems.add(item);
    }

    @Override
    public List<MenuItem> getItemsInOrder()
    {
        return null;
    }

    @Override
    public String getItemNamesInOrder()
    {
        StringBuilder itemListing = new StringBuilder();
        for(MenuItem menuItem : menuItems)
        {
            itemListing.append(String.format("%1$s\r\n", menuItem.getName()));
        }

        return itemListing.toString();
    }
}
