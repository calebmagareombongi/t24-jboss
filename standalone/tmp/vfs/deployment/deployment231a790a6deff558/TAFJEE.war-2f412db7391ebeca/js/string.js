function replaceChar(id) {

var x = document.getElementById(id).value;
c = {	
		  '&':'&amp;',
		  '#':'&#035;', 
	      '<':'&lt;',
  		  '>':'&gt;' ,
		  '"':'&quot;',
		  "'":'&#039;',
		  '/':'&#047;' 		  
  };
 
  var y =  x.replace( /[<&>'"#//]/g, function(s) { 
  	return c[s]; 
  } 
  );
 
  document.getElementById(id).value = y;

}
