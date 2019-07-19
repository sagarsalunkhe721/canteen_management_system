package com.canteenDB.cms.serv;

import java.util.List;

import com.canteenDB.cms.dto.User;

public interface UserService {	
	public void createUser(User user);
	public void removeUser(int userId);
	public void modifyUser(User user);
	public List<User> selectAllUsers();
	public boolean checkUser(User user);
}