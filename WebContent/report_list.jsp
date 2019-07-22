
 <head>
 <link rel="stylesheet"
	href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
<script
	src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="css/style.css">
 </head>
<style>
.dropdown-submenu {
  position: relative;
}

.dropdown-submenu .dropdown-menu {
  top: 0;
  left: 100%;
  margin-top: -1px;
}
</style>
                             
  <div class="dropdown">
    <button class="btn btn-default dropdown-toggle  text-primary" type="button" data-toggle="dropdown">Reports
    <span class="caret"></span></button>
    <ul class="dropdown-menu">
      <li><a tabindex="-1" href="#">Menu</a></li>
     
      <li class="dropdown-submenu">
        <a class="test" tabindex="-1" href="#">Item<span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a tabindex="-1" href="#">Daily Item Report</a></li>
          <li><a tabindex="-1" href="#">Service wise Daily Item Report</a></li>
          <li><a tabindex="-1" href="#">Monthly Item Report</a></li>
          <li><a tabindex="-1" href="#">Service wise Monthly Item Report</a></li>
         </ul>
       </li>
           
         <li class="dropdown-submenu">
        <a class="test" tabindex="-1" href="#">Person<span class="caret"></span></a>
        <ul class="dropdown-menu">
          
        <li class="dropdown-submenu">
            <a class="test" href="#">Daily Person Report <span class="caret"></span></a>
            <ul class="dropdown-menu">
              <li><a href="#">Person wise</a></li>
              <li><a href="#">Person wise Service wise</a></li>
               <li><a href="#">All users</a></li>
              </ul>
          </li>
          
          <li class="dropdown-submenu">
            <a class="test" href="#">Monthly Person Report <span class="caret"></span></a>
            <ul class="dropdown-menu">
              <li><a href="#">Person wise</a></li>
              <li><a href="#">Person wise Service wise</a></li>
               <li><a href="#">All users</a></li>
              </ul>
           </li>
           
            <li class="dropdown-submenu">
          	  <a class="test" href="#">Monthly Printouts <span class="caret"></span></a>
              <ul class="dropdown-menu">
              <li><a href="#">Staff</a></li>
              <li><a href="#">Cash</a></li>
              </ul>
            </li>
           
        </ul>
      </li>
      
      <li class="dropdown-submenu">
        <a class="test" tabindex="-1" href="#">Performance<span class="caret"></span></a>
      	  <ul class="dropdown-menu">
          <li><a tabindex="-1" href="#">Daily</a></li>
          <li><a tabindex="-1" href="#">Monthly</a></li>
          </ul>
       </li>
           
       <li><a tabindex="-1" href="#">Official Guest</a></li>
       
       <li class="dropdown-submenu">
        <a class="test" tabindex="-1" href="#">BACK UPS<span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a tabindex="-1" href="#">Item Price</a></li>
          <li><a tabindex="-1" href="#">Person</a></li>
         </ul>
       	</li>
       
        <li><a tabindex="-1" href="#">Cash Monthly Balance</a></li>
        <li><a tabindex="-1" href="#">Cash Deposit</a></li>
         <li><a tabindex="-1" href="#">Cash Deposit Return</a></li>
        
    </ul>
  </div>


<script>
$(document).ready(function(){
  $('.dropdown-submenu a.test').on("click", function(e){
    $(this).next('ul').toggle();
    e.stopPropagation();
    e.preventDefault();
  });
});
</script>


    