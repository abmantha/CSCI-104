#include "astore.h"
#include "util.h"
using namespace std;

AStore::AStore() {

}


AStore::~AStore() {

	for (std::vector<Product*>::iterator productIt = productsInDBase.begin(); productIt != productsInDBase.end(); ++productIt) {
		delete *productIt; 
	}

	for (std::vector<User*>::iterator userIt = usersInDBase.begin(); userIt != usersInDBase.end(); ++userIt) {
		delete *userIt; 
	}

}


void AStore::addProduct(Product* p) {

	productsInDBase.push_back(p); 
	std::set<std::string> productKeywords = p->keywords(); 

	for (std::set<std::string>::iterator it = productKeywords.begin(); it != productKeywords.end(); ++it) {

		std::string currKeyword = *it; 
		std::map<std::string, std::set<Product*> >::iterator key = keywordsToProducts.find(currKeyword); 

		if (key != keywordsToProducts.end()) {
			(key->second).insert(p); 
		} else {
			std::set<Product*> newListedProducts;
			newListedProducts.insert(p); 
			keywordsToProducts.insert( std::pair<std::string, std::set<Product*> >(currKeyword, newListedProducts) );

		}

	}

}


void AStore::addUser(User* u) {

	bool exists = false;
	for (std::vector<User*>::iterator it = usersInDBase.begin(); it != usersInDBase.end(); ++it) {
		if (*it == u) {
			exists = true;
		}
	}
	if (!exists) {
		std::vector<Product*> cartProducts; 
		usersInDBase.push_back(u);
		userCarts.insert( std::pair<std::string, std::vector<Product*> >(u->getName(), cartProducts) ); 
	}

}


std::vector<Product*> AStore::search(std::vector<std::string>& terms, int type) {

	std::vector<Product*> hits;

	if (terms.size() == 0) {
		return hits;
	}


	if (keywordsToProducts.find(terms[0]) != keywordsToProducts.end()) {
		 
		std::set<Product*> keyProducts = keywordsToProducts.find(terms[0])->second; 

		if (type == 0) {
			std::vector<std::string>::iterator it = terms.begin();
			while (it != terms.end()) {
				string searchKey = *it; 
				std::map<std::string, std::set<Product*> >::iterator mapKey = keywordsToProducts.find(searchKey); 
				if (mapKey != keywordsToProducts.end()) {
					std::set<Product*> nextKeyProducts = mapKey->second;
					keyProducts = setIntersection(keyProducts, nextKeyProducts); 
				}
				++it;
			}
		}

		if (type == 1) {
			std::vector<std::string>::iterator it = terms.begin();
			while (it != terms.end()) {
				string searchKey = *it; 
				std::map<std::string, std::set<Product*> >::iterator mapKey = keywordsToProducts.find(searchKey); 
				if (mapKey != keywordsToProducts.end()) {	//keyword is in the map
					std::set<Product*> nextKeyProducts = mapKey->second;
					keyProducts = setUnion(keyProducts, nextKeyProducts);
				} 
				++it;
			}

		}

		for (std::set<Product*>::iterator it = keyProducts.begin(); it != keyProducts.end(); ++it) {
			hits.push_back(*it); 
		}

	}

	return hits; 

}


void AStore::addToCart(std::string user_name, Product* productToAdd) {

	if (!exists(user_name)) {
		std::cout << "User does not exist in database." << std::endl;
		return;
	}

	std::map<std::string, std::vector<Product*> >::iterator it = userCarts.find(user_name); 
	(it->second).push_back(productToAdd); 

}


void AStore::viewCart(std::string user_name) {

	if (!exists(user_name)) {
		std::cout << "User does not exist in database." << std::endl;
		return;
	}
	

	std::vector<Product*> userProducts = userCarts.find(user_name)->second; 
	for (unsigned int i = 0; i < userProducts.size(); i++) {
		std::cout << "Item " << i+1 << std::endl;
		std::cout << userProducts[i]->displayString() << std::endl; 
		std::cout << userProducts[i]->getPrice() << " " << userProducts[i]->getQty() << " left." << std::endl;
		std::cout << std::endl; 
	}
}


void AStore::buyCart(std::string user_name) {

	if (!exists(user_name)) {
		std::cout << "User does not exist in database." << std::endl;
		return;
	}

	std::vector<Product*> userProducts = userCarts.find(user_name)->second; 
	User* user = getUserByUsername(user_name); 

	std::vector<Product*>::iterator it = userProducts.begin(); 
	for (unsigned int i = 0; i < userProducts.size(); i++) {

		if ( ((*it)->getQty() > 0) && (user->getBalance() >= (*it)->getPrice()) ) {

			userProducts.erase(it); 
			(*it)->subtractQty(1); 
			user->deductAmount((*it)->getPrice()); 

		} else if ((*it)->getQty() == 0 || (user->getBalance() < (*it)->getPrice()) ) {
			++it; 
		}
	}

	userCarts.find(user_name)->second = userProducts; 


}


void AStore::dump(std::ostream& ofile) {

	ofile << "<products>" << std::endl;
	for (std::vector<Product*>::iterator product = productsInDBase.begin(); product != productsInDBase.end(); ++product) {
		(*product)->dump(ofile); 
	}
	ofile << "</products>" << std::endl;

	ofile << "<users>" << std::endl;
	for (std::vector<User*>:: iterator user = usersInDBase.begin(); user != usersInDBase.end(); ++user) {
		(*user)->dump(ofile); 	
	}
	ofile << "</users>" << std::endl;

}


bool AStore::exists(std::string user_name) {
	for (std::vector<User*>::iterator it = usersInDBase.begin(); it != usersInDBase.end(); ++it) {
		if ((*it)->getName() == user_name) {
			return true; 
		}
	}
	return false;
}


User* AStore::getUserByUsername(std::string user_name) {
	for (std::vector<User*>::iterator uIt = usersInDBase.begin(); uIt != usersInDBase.end(); ++uIt) {
		if ((*uIt)->getName() == user_name) {
			return *uIt; 
		}
	}
	return NULL; 
}