package com.canteenDB.cms.dao;

import java.util.List;

import com.canteenDB.cms.dto.Guest;

public interface GuestDao {
	public void save(Guest guest);	
	public void update(Guest guest) ;
	public void deleteById(String guestId);	
	public List<Guest> getAll() ;
//	public int getGuestById();

}
