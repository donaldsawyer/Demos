package com.rwb.restaurant;

import com.rwb.strategies.MenuItem;
import com.rwb.strategies.SalesTaxMenuItem;
import com.rwb.strategies.TaxTypeEnum;

/**
 * Created by Donald on 11/18/2015.
 */
public class DonutMenuItem extends SalesTaxMenuItem
{
    public DonutMenuItem()
    {
        this.name = "Doughnut";
        this.price = 1.99;
    }
}
