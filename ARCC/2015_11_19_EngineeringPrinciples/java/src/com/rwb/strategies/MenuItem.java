package com.rwb.strategies;

/**
 * Created by Donald on 11/18/2015.
 */
public class MenuItem
{
    protected String name;
    protected double price;
    protected TaxTypeEnum taxType;

    public String getName() {
        return name.substring(1);
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setTaxType(TaxTypeEnum taxType) {
        this.taxType = taxType;
    }

    public double calculateTax()
    {
        double taxRate = 0.0;

        switch(taxType)
        {
            case TAX_EXEMPT:
                taxRate = 0.0;
                break;
            case VAT:
                taxRate = 10.0;
                break;
            case SALES:
                taxRate = 7.5;
        }

        return price * taxRate / 100;
    }
}
