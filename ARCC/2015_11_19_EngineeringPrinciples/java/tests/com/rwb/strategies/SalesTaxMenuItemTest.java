package com.rwb.strategies;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Donald on 11/18/2015.
 */
public class SalesTaxMenuItemTest
{
    @Test
    public void CalculateTax_0_dollars()
    {
        SalesTaxMenuItem sut = new SalesTaxMenuItem();
        sut.setPrice(0);

        double taxAmount = sut.calculateTax();

        assertEquals(0.0, taxAmount, 0.01);
    }

}