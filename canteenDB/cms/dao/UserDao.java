package com.canteenDB.cms.dao;
import com.canteenDB.cms.dto.User;
import java.util.List;

public interface UserDao {	
	public void save(User user);	
	public void deleteById(int userId);	
	public void update(User user) ;
	public List<User> getAll() ;
	public boolean validateUser(User user);
}