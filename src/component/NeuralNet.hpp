#ifndef NEURALNET_HPP
#define NEURALNET_HPP

#include "Neuron.hpp"

namespace ae
{
    class NeuralNet : public Drawable
    {
    public:
      static const uint64_t type = "NeuralNet"_type;
      NeuralNet();
      ~NeuralNet();
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
      {
	 states.transform *= getTransform();
	 for(auto it = mNet.begin();it != mNet.end(); it++)
	   target.draw(*((*it).second),states);
      }
      void addNeuron();
      void rmNeuron(int id);
    private:
      int mouseColl(int mx,int my);
      std::map<int,std::shared_ptr<Neuron>> mNet;
      int mSelection;
    };
}

#endif