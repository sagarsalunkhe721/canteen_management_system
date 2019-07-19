package com.canteenDB.cms.cntr;

import java.util.List;

//import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.canteenDB.cms.dto.Item;
import com.canteenDB.cms.dto.Person;
import com.canteenDB.cms.serv.ItemService;
import com.canteenDB.cms.serv.PersonService;

@Controller
public class PersonController {
	
	@Autowired
	private PersonService personService;
	
	/*
	 * @RequestMapping(value = "/prep_login_form.htm") public String
	 * prepLoginForm(ModelMap model) { model.put("user", new User()); return
	 * "index"; }
	 */
	
	@RequestMapping(value = "/prep_person_form.htm")
	public String personRegForm(ModelMap model) {
		model.put("person", new Person());
		return "add_person";
	}
	
	@RequestMapping(value = "/add_person.htm")
	public String addPerson(Person person,ModelMap model) {
		personService.Add(person);
		model.put("person", new Person());
		List<Person> ulist = personService.GetAll();
		model.put("ul", ulist);
		return "person";
	}
	
	@RequestMapping(value = "/person_list.htm")
	public String personList(ModelMap model) {
		List<Person> ulist = personService.GetAll();
		model.put("ul", ulist);
		return "person";
	}
	
	@RequestMapping(value = "/delete_person.htm")
	public String deletePerson(@RequestParam String personId,ModelMap model) {
		personService.DeleteById(personId);
		List<Person> ulist = personService.GetAll();
		model.put("ul", ulist);
		return "person";
	}
	
}