#ifndef ASTORE_H
#define ASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include "datastore.h"
#include "product.h"
#include "user.h"


class AStore : public DataStore {

	public: 
		AStore(); 

		~AStore();

		void addProduct(Product* p); 

		void addUser(User* u); 

		std::vector<Product*> search(std::vector<std::string>& terms, int type);

		void dump(std::ostream& ofile); 

		void addToCart(std::string user_name, Product* productToAdd); 

		void viewCart(std::string user_name); 

		void buyCart(std::string user_name); 

	private: 
		bool exists(std::string user_name);

		User* getUserByUsername(std::string user_name);

		std::map<std::string, std::set<Product*> > keywordsToProducts; 

		std::map<std::string, std::vector<Product*> > userCarts;

		std::vector<Product*> productsInDBase; 

		std::vector<User*> usersInDBase; 




}; 
#endif