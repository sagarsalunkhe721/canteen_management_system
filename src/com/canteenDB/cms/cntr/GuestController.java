package com.canteenDB.cms.cntr;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.canteenDB.cms.dto.Guest;
import com.canteenDB.cms.dto.Item;
import com.canteenDB.cms.serv.GuestService;

@Controller
public class GuestController {

	@Autowired
	private GuestService guestService;
	
	@RequestMapping(value = "/prep_guest_form.htm")
	public String itemRegForm(ModelMap model) {
		model.put("guest", new Guest());
		return "add_guest";
	}
	@RequestMapping(value = "/add_guest.htm")
	public String addGuest(Guest guest,ModelMap model) {
		guestService.createGuest(guest);
		model.put("guest", new Guest());
		List<Guest> ulist = guestService.selectAllGuests();
		model.put("ul", ulist);
		return "guest";
	}
	@RequestMapping(value = "/guest_list.htm")
	public String guestList(ModelMap model) {
		List<Guest> ulist = guestService.selectAllGuests();
		model.put("ul", ulist);
		return "guest";
	}
	@RequestMapping(value = "/delete_guest.htm")
	public String deleteItem(@RequestParam String guestId,ModelMap model) {
		guestService.removeGuest(guestId);
		List<Guest> ulist = guestService.selectAllGuests();
		model.put("ul", ulist);
		return "guest";
	}
}
