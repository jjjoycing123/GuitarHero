/**********************************************************************
 *  readme.txt template                                                   
 *  Plucking a Guitar String
 **********************************************************************/

Name:
CS Login: John Nay 


Hours to complete assignment: 10


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, in GutiarHero.cpp I used 3 for loops to create 3 parallel vectors to create samples to be played by the event loop.  In the event loop I extended the switch statement to respond to all the following key presses: "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ". I generated the samples with my guitarstring class. 




/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 *  If you completed the AutoGuitar, what does it play?
 **********************************************************************/
No.


/**********************************************************************
 *  Does your GuitarString implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, when executed the test prints “running 1 test case no errors detected.”



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Just the CPP reference website and the SFML reference website. 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Generating random numbers in the guitarsring class took more time than I anticipated. My only major issue was figuring out how to synch up the 3 length 37 vectors in GuitarHero.cpp. For hours I was trying to use one for loop to build the vectors, and then I implemented 3 different loops and my code worked! Below is my implementation:

  for(int i = 0; i < 37; i++){
  freq = CONCERT_A * pow(2, (i -24)/12.0);
  GuitarString gs2 = GuitarString(freq);
  samples = makeSamplesFromString(gs2);
  vec_samples.push_back(samples);
  }

  for(int i = 0; i < 37; i++){
  sf::SoundBuffer buf2; 
  if (!buf2.loadFromSamples(&vec_samples.at(i)[0], vec_samples.at(i).size(), 2, SAMPLES_PER_SEC))
    throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
  soundbuffers.push_back(buf2);
  }

  for(int i = 0; i < 37; i++){
  sf::Sound sound2;
  sound2.setBuffer(soundbuffers.at(i));
  sounds.push_back(sound2); 
  }




/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A

