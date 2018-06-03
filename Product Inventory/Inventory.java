/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package product.inventory;
import java.util.LinkedList;
import java.util.List;
/**
 *
 * @author Adrian's Beast
 */
public class Inventory {
    public Inventory(List<Product>product)
    {
        products=new LinkedList<>();
        products=product;
    }
    public double getPriceOfItemInInventory(Product product)
    {
        if(products.contains(product))
        {
            return product.getPrice();
        }
        else
        {
           return 0; 
        }
    }
    public String remove(Product product)
    {
        if(products.contains(product))
        {
            products.remove(product);
            return "Product removed";
        }
        else
            return "Product not found";
    }
    public void removeAll()
    {
        products.clear();
    }
    public void displayProducts()
    {
        if(products.size()>=1)
        {
             for(Product p:products)
             {
                System.out.printf("The Product in the list is %s, the price of the item is %f, the quantity on hand is %d \n ",p.getName(), p.getPrice(),p.getQuantity());
             }
        }
        else
        {
            System.out.println("There are no products to be displayed");
        }
    }
    public int productCount()
    {
        return products.size();
    }
    public void addProduct(Product product)
    {
        products.add(product);
    }
    private List<Product>products;
}
