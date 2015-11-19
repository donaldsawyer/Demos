package com.rwb;

import com.rwb.restaurant.*;
import com.rwb.strategies.IOrder;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args)
    {
        MerchandiseOrder merchandiseOrder = new MerchandiseOrder();
        merchandiseOrder.addMenuItem(new BananaItem());
        merchandiseOrder.addMenuItem(new CommemorativeCupMenuItem());
        merchandiseOrder.addMenuItem(new CommemorativeCupMenuItem());

        FoodOrder foodOrder = new FoodOrder();
        foodOrder.addMenuItem(new BananaItem());
        foodOrder.addMenuItem(new DonutMenuItem());
        foodOrder.addMenuItem(new BananaItem());

        List<IOrder> orders = new ArrayList<IOrder>();
        orders.add(merchandiseOrder);
        orders.add(foodOrder);

        printOrderTotals(orders);
    }

    public static void printOrderTotals(List<? extends IOrder> orders)
    {
        for(IOrder order : orders)
        {
            System.out.print(order.getItemNamesInOrder());
            System.out.println(String.format("Order Total: $%1$s", order.calculateTotal()));
            System.out.println("");
        }
    }
}
