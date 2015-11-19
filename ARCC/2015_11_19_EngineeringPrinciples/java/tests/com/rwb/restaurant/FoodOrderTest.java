package com.rwb.restaurant;

import com.rwb.strategies.MenuItem;
import com.rwb.strategies.TaxTypeEnum;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Donald on 11/18/2015.
 */
public class FoodOrderTest
{

    @Test
    public void testCalculateTotal_noItems() throws Exception
    {
        FoodOrder sut = new FoodOrder();

        double total = sut.calculateTotal();

        assertEquals(0.0, total, 0.01);
    }

    @Test
    public void testCalculateTotal_3Items() throws Exception
    {
        FoodOrder sut = new FoodOrder();
        sut.addMenuItem(new DonutMenuItem());

        MenuItem bananaMenuItem = new MenuItem();
        bananaMenuItem.setName("Banana");
        bananaMenuItem.setPrice(0.50);
        bananaMenuItem.setTaxType(TaxTypeEnum.TAX_EXEMPT);
        sut.addMenuItem(bananaMenuItem);

        double expectedTotal = 1.99 + 1.99*7.5/100 + .5;
        double actualTotal = sut.calculateTotal();

        assertEquals(expectedTotal, actualTotal, 0.01);
    }

    @Test
    public void testAddMenuItem() throws Exception
    {

    }
}