/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package product.inventory;

/**
 *
 * @author Adrian's Beast
 */
public class Product {
    private double price;
    private int id;
    private int itemQuantity;
    private String itemName;
    /**
     * @param args the command line arguments
     */
    public Product(double itemPrice, int itemId, int quantityOfItem, String name)
    {
        this.price=itemPrice;
        this.id=itemId;
        this.itemQuantity=quantityOfItem;
        this.itemName=name;
    }

    public String getName() {
        return itemName;
    }
    public int getQuantity()
    {
        return itemQuantity;
    }

    double getPrice() {
        return price;
    }
}
