package com.canteenDB.cms.dao;
import com.canteenDB.cms.dto.Item;
import java.util.List;

public interface ItemDao {	
	public void save(Item item);	
	public void deleteById(String itemId);	
	public void update(Item item) ;
	public List<Item> getAll() ;
//	public Item getElementById(String itemId);
}