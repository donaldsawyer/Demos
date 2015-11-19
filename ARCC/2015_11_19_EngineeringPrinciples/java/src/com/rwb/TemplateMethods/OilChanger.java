package com.rwb.TemplateMethods;

/**
 * Created by Donald on 11/19/2015.
 */
public abstract class OilChanger
{
    public abstract void pullCarInGarageBay();
    public abstract void openHood();
    public abstract void changeOil();
    public abstract void closeHood();
    public abstract void exitGarageBay();

    // Template Method //
    // all subclasses implement the methods above, but the process of changing oil is always the same as below //
    public final void performOilChange()
    {
        pullCarInGarageBay();;
        openHood();
        changeOil();
        closeHood();
        exitGarageBay();
    }
}
