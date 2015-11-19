package com.rwb.restaurant;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Donald on 11/18/2015.
 */
public class DonutMenuItemTest
{
    @Test
    public void CalculateTax()
    {
        DonutMenuItem sut = new DonutMenuItem();

        double taxAmount = sut.calculateTax();

        assertEquals(7.5*1.99/100, taxAmount, 0.01);
    }
}