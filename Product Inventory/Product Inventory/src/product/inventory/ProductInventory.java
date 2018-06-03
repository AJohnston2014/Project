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
public class ProductInventory {
    public static void main(String[] args) {
        // TODO code application logic here
        List<Product> product = new LinkedList<Product>();
        Product milk=new Product(25.20,1,1,"Milk");
        product.add(milk);
        Product moon=new Product(24.20,1,1,"moon");
        Inventory inventory=new Inventory(product);
       System.out.println( inventory.getPriceOfItemInInventory(moon));
       inventory.displayProducts();
       inventory.removeAll();
       inventory.displayProducts();
       inventory.addProduct(moon);
       inventory.addProduct(milk);
       inventory.displayProducts();
        
    }
    
}
