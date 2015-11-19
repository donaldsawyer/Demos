package com.rwb.strategies;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Donald on 11/19/2015.
 */
public class ExemptTaxMenuItemTest
{
    @Test
    public void testCalculateTaxAmount() throws Exception
    {
        ExemptTaxMenuItem sut = new ExemptTaxMenuItem();
        sut.setPrice(15);

        double expectedTaxAmount = 15*0.0/100;
        double actualTaxAmount = sut.calculateTax();

        assertEquals(expectedTaxAmount, actualTaxAmount, 0.01);
    }
}