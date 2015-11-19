package com.rwb.strategies;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Donald on 11/18/2015.
 */
public class MenuItemTest
{

    @Test
    public void testCalculateTax_sales() throws Exception
    {
        MenuItem sut = new MenuItem();
        sut.setName("Doughnut");
        sut.setPrice(1.99);
        sut.setTaxType(TaxTypeEnum.SALES);

        double taxAmount = sut.calculateTax();

        assertEquals(7.5*1.99/100, taxAmount, 0.01);
    }

    @Test
    public void testCalculateTax_vat() throws Exception
    {
        MenuItem sut = new MenuItem();
        sut.setName("Commemorative Cup");
        sut.setPrice(10.0);
        sut.setTaxType(TaxTypeEnum.VAT);

        double taxAmount = sut.calculateTax();

        assertEquals(10*10.0/100, taxAmount, 0.01);
    }

    @Test
    public void testCalculateTax_exempt() throws Exception
    {
        MenuItem sut = new MenuItem();
        sut.setName("Banana");
        sut.setPrice(0.50);
        sut.setTaxType(TaxTypeEnum.TAX_EXEMPT);

        double taxAmount = sut.calculateTax();

        assertEquals(0.0, taxAmount, 0.01);
    }
}