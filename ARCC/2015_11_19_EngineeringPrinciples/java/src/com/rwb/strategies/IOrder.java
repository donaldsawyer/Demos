package com.rwb.strategies;

import java.util.List;

/**
 * Created by Donald on 11/18/2015.
 */
public interface IOrder
{
    public double calculateTotal();
    public void addMenuItem(MenuItem item);
    public List<MenuItem> getItemsInOrder();
    public String getItemNamesInOrder();
}
