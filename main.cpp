#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"

void printHelp(char * argv[])
{
  std::cout << "Usage: " << argv[0] << " <contour-file>" << std::endl;
}

int loadContour(const std::string & fileName,std::vector< cv::Point2f > & contour)
{
  size_t nElems = 0;
  float elem;
  cv::Point2f point;
  std::ifstream contourFile(fileName.c_str());
  if (contourFile.is_open())
  {
    while ( contourFile.good())
    {
      contourFile >> elem;
      if(!contourFile.eof())
      {
        if(nElems%2==0)
        {
          point.x=elem;
        }
        else
        {
          point.y=elem;
          contour.push_back(point);
        }
        nElems++;
      }
    }
    contourFile.close();

    if(nElems%2==0)
    {
      return 0;
    }
    else
    {
      std::cout << "Invalid number of elements in file: " << fileName << std::endl;
      return EXIT_FAILURE;
    }
  }
  else
  {
    std::cout << "Unable to open file: " << fileName << std::endl;
    return EXIT_FAILURE;
  }
}

int main(int argc, char *argv[])
{  
  if(argc!=2)
  {
    printHelp(argv);
    return EXIT_FAILURE;
  }

  // Read the input contour from file
  std::string contourFileName = std::string(argv[1]);
  std::vector< cv::Point2f > contour;
  if(loadContour(contourFileName,contour))
  {
    return EXIT_FAILURE;
  }

  // Compute the moments for the input contour
  cv::Moments moments = cv::moments( contour, false );

  // Print the moments
  std::cout<<"m00: "<<moments.m00<<std::endl;
  std::cout<<"m01: "<<moments.m01<<std::endl;
  std::cout<<"m02: "<<moments.m02<<std::endl;
  std::cout<<"m03: "<<moments.m03<<std::endl;
  std::cout<<"m10: "<<moments.m10<<std::endl;
  std::cout<<"m11: "<<moments.m11<<std::endl;
  std::cout<<"m12: "<<moments.m12<<std::endl;
  std::cout<<"m20: "<<moments.m20<<std::endl;
  std::cout<<"m21: "<<moments.m21<<std::endl;
  std::cout<<"m30: "<<moments.m30<<std::endl;
  std::cout<<"mu02: "<<moments.mu02<<std::endl;
  std::cout<<"mu03: "<<moments.mu03<<std::endl;
  std::cout<<"mu11: "<<moments.mu11<<std::endl;
  std::cout<<"mu12: "<<moments.mu12<<std::endl;
  std::cout<<"mu20: "<<moments.mu20<<std::endl;
  std::cout<<"mu21: "<<moments.mu21<<std::endl;
  std::cout<<"mu30: "<<moments.mu30<<std::endl;
  std::cout<<"nu02: "<<moments.nu02<<std::endl;
  std::cout<<"nu03: "<<moments.nu03<<std::endl;
  std::cout<<"nu11: "<<moments.nu11<<std::endl;
  std::cout<<"nu12: "<<moments.nu12<<std::endl;
  std::cout<<"nu20: "<<moments.nu20<<std::endl;
  std::cout<<"nu21: "<<moments.nu21<<std::endl;
  std::cout<<"nu30: "<<moments.nu30<<std::endl;

  return EXIT_SUCCESS;
}
