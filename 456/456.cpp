#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// ȫ�ֱ���

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold=30;
//int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";
char* window_name1="Edge yuan";
/**
 * @���� CannyThreshold
 * @��飺 trackbar �����ص� - Canny��ֵ�������1:3
 */
void CannyThreshold(int, void*)
{
  /// ʹ�� 3x3�ں˽���
  blur( src_gray, detected_edges, Size(3,3) );

  /// ����Canny����
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

  /// ʹ�� Canny���������Ե��Ϊ������ʾԭͼ��
  dst = Scalar::all(0);

  src.copyTo( dst, detected_edges);
  imshow( window_name, dst );
  imshow(window_name1,src );
 }


/** @���� main */
int main( int argc, char** argv )
{
  /// װ��ͼ��
  src = imread("1.jpg",1);

  if( !src.data )
  { return -1; }

  /// ������srcͬ���ͺʹ�С�ľ���(dst)
  dst.create( src.size(), src.type());

  /// ԭͼ��ת��Ϊ�Ҷ�ͼ��
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// ������ʾ����
 // namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  /// ����trackbar
  //createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );

  /// ��ʾͼ��
 CannyThreshold(0,0);

  /// �ȴ��û���Ӧ
  waitKey(0);

  return 0;
  }
