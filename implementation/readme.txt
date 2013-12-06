1. Describe the state of your program, exactly what works and what does not work. 
	
	What works:
		- The displayAllProducts command works. 
		- The program can read the file and add the products to the 
			productcollection object which is an array of bintrees.
		- It can also parse the read-in information and print out all the 
			products that correspond to each genre object.
		- displayAllProducts prints with the proper formatting.
		- The customer historycommand works. It adds the events from the 
			commands to the corresponding customer's history.
		- Customers are also properly read in from the files and the
			customerindex is properly populated as well as the customer's 
			history object. Memory management for that is handled properly.
		- The error objects are set up and working.
		- The bintree class works.

	What doesn't work:
		- The product in/out status hasn't been finished. I spent many hours
			trying to get it to work AND be extensible and in the end I ran
			out of time. The problem mostly lies with all the complexity that
			comes with productformatcollection and productformat classes.
		- The customer history command works but it doesn't display the events
			properly. Again, ran out of time.

2. Describe your hash table(s): what they are used for and file found in. 
	(Include any hash factories.) 
	
	- I used the stl hashtable for storing objects in the customerindex and 
		productData in the product object.
	- I unfortunately did not get time to implement my own hashtable.

3. Describe which file and which function you read the movie data, high level 
	function call, 
    i.e., how/where it gets into your movie collections. 

    - The manager class has an getInput method that creates an instance of the
    	input object which reads the file input and returns the data.
    - Then the manager uses its productfactory to create a new product based on
    	the data read in.
    - During creation, the product is passed the data that was read in and the
    	derived genre class then parses that data and stores it in the 
    	productData hashmap in its base class(product.h).
    - After the data is inserted, productFactor inserts a pointer to the product
    	into the productcollection object which is an alphabetical array of
    	bintrees. 

4. Describe which file and which function you read the command data, high level 
	function call, 
    i.e., how/where you perform the commands/transactions. 

    - The manager class has an getInput method that creates an instance of the
    	input object which reads the file input and returns the data.
    - Then the manager uses its commandfactory to create a new command based on
    	the data read in.
    - During creation, the command is passed the data that was read in and the
    	derived command class acts accordingly when the excute method is run by
    	manager. 
    - In order to get basic functionality working for return and borrow, I had 
    	the commandfactory just pass in the data via an event object which is
    	then added to the customer's history through the customerindex's 
    	addtransaction method.
   	- A product search method needs to be added in the product class that 
   		finds the product corresponding to the arguments fo the command and
   		then adds that data to the customer's history so that each genre class
   		can be responsible for its own printing.


5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.) 
    If you feel they do not violate the open-closed design principle, explain. 

    - I actually don't have any dirty little secrets that I can think of. I 
    	tried really hard to not violate the open-closed principle as I was 
    	coding, but I think that also cost me a lot of time which makes me 
    	regret not taking some more shortcuts like that.

    - I do, however, have some memory leaks. I worked at keeping up with them
    	for a while, but at the end I was so rushed I didn't get time to track
    	them down.

6. Describe anything you are particularly proud of ... 

	- I'm proud of the fact that the project, while not finished, is fairly 
		flexible and extensible with no open-closed princple violations that
		I can think of. The design may be large and complicated, but it is set
		upon so that it can be expanded upon.