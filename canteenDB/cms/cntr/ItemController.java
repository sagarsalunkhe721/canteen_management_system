package com.canteenDB.cms.cntr;

import java.util.List;

//import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.canteenDB.cms.dto.Item;
import com.canteenDB.cms.serv.ItemService;

@Controller
public class ItemController {
	
	@Autowired
	private ItemService itemService;
	
	/*
	 * @RequestMapping(value = "/prep_login_form.htm") public String
	 * prepLoginForm(ModelMap model) { model.put("user", new User()); return
	 * "index"; }
	 */
	
	@RequestMapping(value = "/prep_item_form.htm")
	public String itemRegForm(ModelMap model) {
		model.put("item", new Item());
		return "add_item";
	}
	
	@RequestMapping(value = "/add_item.htm")
	public String addItem(Item item,ModelMap model) {
		itemService.createItem(item);
		model.put("item", new Item());
		List<Item> ulist = itemService.selectAllItems();
		model.put("ul", ulist);
		return "item";
	}
	
	@RequestMapping(value = "/item_list.htm")
	public String itemList(ModelMap model) {
		List<Item> ulist = itemService.selectAllItems();
		model.put("ul", ulist);
		return "item";
	}
	
	@RequestMapping(value = "/delete_item.htm")
	public String deleteItem(@RequestParam String itemId,ModelMap model) {
		itemService.removeItem(itemId);
		List<Item> ulist = itemService.selectAllItems();
		model.put("ul", ulist);
		return "item";
	}
	
	@RequestMapping(value= "/select_item.htm")
	public String updateItem(@RequestParam Item item, ModelMap model) {
		itemService.modifyItem(item);
		model.put("item", new Item());
		return "add_item";
	}
	
}