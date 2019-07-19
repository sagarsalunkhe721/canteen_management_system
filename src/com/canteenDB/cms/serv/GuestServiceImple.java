package com.canteenDB.cms.serv;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.canteenDB.cms.dao.GuestDao;
import com.canteenDB.cms.dto.Guest;

@Service
public class GuestServiceImple implements GuestService {

	@Autowired
	private GuestDao guestDao;
	
	public void createGuest(Guest guest) {
		guestDao.save(guest);
		
	}

	
	public void removeGuest(String guestId) {
		guestDao.deleteById(guestId);
		
	}

	
	public void modifyGuest(Guest guest) {
		guestDao.update(guest);
		
	}

	
	public List<Guest> selectAllGuests() {
		
		return guestDao.getAll();
	}

}
