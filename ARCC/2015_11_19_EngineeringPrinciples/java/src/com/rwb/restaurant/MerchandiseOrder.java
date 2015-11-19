package com.rwb.restaurant;

import com.rwb.strategies.IOrder;
import com.rwb.strategies.MenuItem;
import com.rwb.strategies.SalesTaxMenuItem;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Donald on 11/19/2015.
 */
public class MerchandiseOrder implements IOrder
{
    private double merchandiseFee = 1.5;
    private List<MenuItem> menuItems = new ArrayList<MenuItem>();

    @Override
    public double calculateTotal() {
        double totalAmount = 0.0;

        for(MenuItem menuItem : menuItems)
        {
            totalAmount += menuItem.getPrice() + menuItem.calculateTax() + merchandiseFee;
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
        return menuItems;
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
