package com.rwb.strategies;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Donald on 11/19/2015.
 */
public class VatTaxMenuItemTest
{
    @Test
    public void testCalculateTax() throws Exception
    {
        VatTaxMenuItem sut = new VatTaxMenuItem();
        sut.setPrice(11);

        double expectedTaxAmount = 11*10.0/100;
        double actualTaxAmount = sut.calculateTax();

        assertEquals(expectedTaxAmount, actualTaxAmount, 0.01);
    }
}