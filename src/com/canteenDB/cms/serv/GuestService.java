package com.canteenDB.cms.serv;
import java.util.List;

import com.canteenDB.cms.dto.Guest;


public interface GuestService {
	public void createGuest(Guest guest);
	public void removeGuest(String guestId);
	public void modifyGuest(Guest guest);
	public List<Guest> selectAllGuests();
}
