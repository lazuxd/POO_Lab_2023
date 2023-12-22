#include <iostream>
#include <vector>

namespace MLLib1
{
    class LinearRegression
    {
        private:
            double w, b; // parametrii
            std::string optimizationMethod;
        
        public:
            LinearRegression(std::string _optimizationMethod)
            : optimizationMethod(_optimizationMethod)
            {
                std::cout << "Constructorul MLLib1::LinearRegression()" << std::endl;
            }

            void train(const std::vector<double>& x, const std::vector<double>& y, int numIterations)
            {
                std::cout << "Antrenează modelul din MLLib1::LinearRegression" << std::endl;
            }

            double predict(double x)
            {
                return w*x + b;
            }
    };
}

namespace MLLib2
{
    class LinearRegression
    {
        private:
            double w, b;
        
        public:
            LinearRegression()
            {
                std::cout << "Constructorul MLLib2::LinearRegression()" << std::endl;
            }

            LinearRegression& fit(const std::vector<double>& x, const std::vector<double>& y)
            {
                std::cout << "Se antrenează modelul din MLLib2::LinearRegression" << std::endl;
                return *this;
            }

            void predict(double x, double& y)
            {
                y = w*x + b;
            }
    };
}

class LinearRegressionAdapterComposition
{
    private:
        MLLib2::LinearRegression* lr;
    
    public:
        LinearRegressionAdapterComposition(MLLib2::LinearRegression* mlLib2Model)
        : lr(mlLib2Model)
        {
            std::cout << "Constructorul LinearRegressionAdapterComposition()" << std::endl;
        }

        void train(const std::vector<double>& x, const std::vector<double>& y, int numIterations)
        {
            std::cout << "Se apelează metoda .train() din LinearRegressionAdapterComposition" << std::endl;
            lr->fit(x, y);
        }

        double predict(double x)
        {
            double y;
            lr->predict(x, y);
            return y;
        }
};

class LinearRegressionAdapterInheritance : private MLLib2::LinearRegression
{    
    public:
        LinearRegressionAdapterInheritance()
        : MLLib2::LinearRegression()
        {
            std::cout << "Constructorul LinearRegressionAdapterInheritance()" << std::endl;
        }

        void train(const std::vector<double>& x, const std::vector<double>& y, int numIterations)
        {
            std::cout << "Se apelează metoda .train() din LinearRegressionAdapterInheritance" << std::endl;
            MLLib2::LinearRegression::fit(x, y);
        }

        double predict(double x)
        {
            double y;
            MLLib2::LinearRegression::predict(x, y);
            return y;
        }
};

int main()
{
    // MLLib2::LinearRegression lrModelLib2 = MLLib2::LinearRegression();
    // LinearRegressionAdapterComposition lrModel(&lrModelLib2);
    LinearRegressionAdapterInheritance lrModel;

    std::vector<double> x{1.2, 3.4, 0.1};
    std::vector<double> y{3.1, 2.5, 4.2};

    lrModel.train(x, y, 100);

    double result = lrModel.predict(6.0);

    std::cout << "Rezultatul obtinut este: " << result << std::endl; 

    return 0;
}