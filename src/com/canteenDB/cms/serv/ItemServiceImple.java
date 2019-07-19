package com.canteenDB.cms.serv;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.canteenDB.cms.dao.ItemDao;
import com.canteenDB.cms.dto.Item;


@Service
public class ItemServiceImple implements ItemService {
	@Autowired
	private ItemDao itemDao;
	
	
	public void createItem(Item item) {
		itemDao.save(item);
	}
	
	public void removeItem(String itemId) {
		itemDao.deleteById(itemId);
	}
	
	public void modifyItem(Item item) {
		itemDao.update(item);
	}
	
	public List<Item> selectAllItems() {
		return itemDao.getAll();
	}
	
}