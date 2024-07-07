import Foundation

class Chart {
    private func vettingData() {
        print("remove non valid values -> ", terminator: "")
    }
    
    private func featuresExtraction() {
        print("extract chart data -> ", terminator: "")
    }
    
    // Steps requiring peculiar implementations
    // are "placeholders" in base class
    func readData() {
        fatalError("This method should be overridden by subclass")
    }
    
    func drawData() {
        fatalError("This method should be overridden by subclass")
    }
    
    // Standardize the skeleton of an algorithm
    // in a base class "template method"
    func execute() {
        readData()
        vettingData()
        featuresExtraction()
        drawData()
    }
}

class LineChart: Chart {
    // Derived classes implement placeholder methods
    override func readData() {
        print("read LineChart data -> ", terminator: "")
    }
    
    override func drawData() {
        print("Draw data as line chart", terminator: "")
    }
}

class PieChart: Chart {
    // Derived classes implement placeholder methods
    override func readData() {
        print("read PieChart data -> ", terminator: "")
    }
    
    override func drawData() {
        print("Draw data as pie chart", terminator: "")
    }
}

// Main execution
let charts: [Chart] = [LineChart(), PieChart()]

for chart in charts {
    chart.execute()
    print()
}

/**
 read LineChart data -> remove non valid values -> extract chart data -> Draw data as line chart
 read PieChart data -> remove non valid values -> extract chart data -> Draw data as pie chart
 */
