#include <iostream>
#include <cmath>

typedef struct line_{
	double b,c;
	struct line_* next;
}line;

class Point{
	public:
		int x, y;

		Point(int pos_x, int pos_y){
			x = pos_x;
			y = pos_y;
		}
};

class Geometry{
	public:
		Geometry(){
			num_points = 0;
			line_head = new line;
			line_head->b = 0;
			line_head->c = 0;
			line_head->next = NULL;
		}

		void addPoint(const Point &point) {
			point_array[num_points ++] = new Point(point.x, point.y);
		}

		void printDistance();

		void printNumMeets();

		void deletePoints();

	private:
		Point* point_array[100];
		line* line_head;
		int num_points;
};

double getDistance(int x, int y){
	return sqrt(pow(x, 2) + pow(y,2));
}


void Geometry::printDistance() {
	for(int i = 0; i < num_points; i++){
		for(int j=i+1; j<num_points; j++) {
			int x1 = point_array[i]->x; int x2 = point_array[j]->x;
			int y1 = point_array[i]->y; int y2 = point_array[j]->y;
			std::cout << i << "와 " << j << "번째 점의 거리는 " << getDistance(x1-x2,y1-y2) << " 입니다." << std::endl;
		}
	}
}

void getLine(line* line, Point* p1, Point* p2){
	double tangent = (double)(p1->y-p2->y)/(p1->x-p2->x);
	double c = p1->y-tangent*(p1->x);
	line->b = -tangent;
	line->c = -c;
	std::cout << "b = " << line->b << ", c = " << line->c <<std::endl;
}
	

void Geometry::printNumMeets(){
	int num_meet = 0;
	line* ptr = line_head;
	line* ptr2 = NULL;
	line* prev = NULL;
	for(int i=0; i<num_points; i++)
	{
		for(int j=i+1; j<num_points;j++){
			if( !ptr->next) {
				ptr->next = new line;
			}
			ptr = ptr->next;
			ptr->next = NULL;
			getLine(ptr, point_array[i], point_array[j]);
		}
	}
	// 일치하는 거 빼기
	for(ptr=line_head->next; ptr ; ptr=ptr->next){
		for(prev = ptr, ptr2 = ptr->next; ptr2 ; ptr2 = ptr2 -> next){
			if(ptr->b == ptr2->b && ptr->c == ptr2->c){
				std::cout << "ptr->b = " << ptr->b << " ptr->c = " << ptr->c<<std::endl;
				prev->next = ptr2->next;
				line *temp = ptr2;
				ptr2 = prev;
				delete temp;
			}else{
				prev=ptr2;
			}
		}
	}


	//if not in parallel, num_meet +1
	for(ptr=line_head->next; ptr ; ptr=ptr->next){
		for(ptr2 = ptr->next; ptr2 ; ptr2 = ptr2 -> next){
			if(!(ptr->b == ptr2->b && ptr->c != ptr2->c)){
				num_meet++;
			}
		}
	}

	std::cout << "모든 점들을 잇는 직선들 간의 교점의 수는 " << num_meet << std::endl;
		
}

void Geometry::deletePoints(){
	for(int i= 0; i<num_points; i++){
		delete point_array[i];
	}
	line* ptr;
	for(ptr = line_head; ptr;){
		line* temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}

int main(){
	Geometry geometry;
	Point p1 = Point(0, 0);
	Point p2 = Point(1, 2);
	Point p3 = Point(3, 4);
	Point p4 = Point(3, 1);
	geometry.addPoint(p1);
	geometry.addPoint(p2);
	geometry.addPoint(p3);
	geometry.addPoint(p4);
	geometry.printDistance();
	geometry.printNumMeets();

	geometry.deletePoints();
}

