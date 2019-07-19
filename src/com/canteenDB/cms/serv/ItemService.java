package com.canteenDB.cms.serv;

import java.util.List;

import com.canteenDB.cms.dto.Item;

public interface ItemService {	
	public void createItem(Item item);
	public void removeItem(String itemId);
	public void modifyItem(Item item);
	public List<Item> selectAllItems();
}