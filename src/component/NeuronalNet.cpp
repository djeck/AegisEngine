#include "NeuronalNet.hpp"

ae::NeuronalNet::NeuronalNet()
{
  mSelection=-1;
  ae::Application::EventHandler func;
    
    func = [this](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
            {
                PRINT("Ok reset selection");
		mSelection=-1;
            }
        else
	{
	  int ret = mouseColl(event.mouseButton.x,event.mouseButton.y);
	  if(ret<0 && mSelection>=0 && mNet.count(mSelection)==1)
	    mNet[mSelection]->setPosition(sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
	  else if(ret>=0 && mNet.count(ret)==1)
	    mSelection=ret;
	}
        return true;
    };
    ae::Application::addEventHandler(sf::Event::MouseButtonPressed,func);
}
void ae::NeuronalNet::addNeuron()
{
  ae::Neuron::Callback func2;
  func2 = [this](int id)
  {
      PRINT("Test Neuron %d Selected",id);
      mSelection=id;
      return false;
  };
  auto neuron = std::make_shared<ae::Neuron>(sf::Vector2f(0,0),func2);
  
  if(mNet.count(neuron->getId())==0)
    mNet.insert(std::pair<int,std::shared_ptr<Neuron>>(neuron->getId(),neuron));
  else
    PRINT("Error neuron id %d already in map (%d)",neuron->getId(),mNet.count(neuron->getId()));
  PRINT("Ok neuron id: %d added to map",neuron->getId());
}

void ae::NeuronalNet::rmNeuron(int id)
{
  for(auto it = mNet.begin(); it != mNet.end();it++)
    if((*it).second->getId()==id)
    {
      mNet.erase(it);
      return;
    }
    PRINT("Error no neuron %d to delete",id);
}

ae::NeuronalNet::~NeuronalNet()
{

}
int ae::NeuronalNet::mouseColl(int mx,int my)
{
  for(auto it = mNet.begin(); it != mNet.end();it++)
    if((*it).second->collision(mx,my))
      return (*it).first;
  return -1;
}
