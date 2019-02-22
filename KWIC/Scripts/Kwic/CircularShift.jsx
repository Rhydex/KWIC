class CircularShift extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            list: this.props.list || [],
            shift: []
        }
    }
    componentWillReceiveProps(newProps) {
        if (this.props == newProps) {return;}
        this.splitLines();
    }
    splitLines = () => {
        let tempList = this.state.list;
        let listOfSplits = [];
        tempList.forEach((line) => {
            listOfSplits.push(line.split(" "));
        });
        this.getLineFromList(listOfSplits);
    }
    getLineFromList = (listOfSplits) => {
        let shiftedList = [];
        listOfSplits.forEach((list) => {
            this.getShiftedLines(list).forEach((str) => {
                shiftedList.push(str);
            });
        });
        this.setState({
            shift: shiftedList
        })
    }
    getShiftedLines = (list) => {
        let listOfShifts = [];
        let tempList = list;
        listOfShifts.push(tempList.join(" "));
        let firstWord = tempList.shift();
        tempList.push(firstWord);
        while(tempList[0] != firstWord) {
            listOfShifts.push(tempList.join(" "));
            tempList.push(tempList.shift());
        }
        return (listOfShifts);
    }
    render() {
        return (
            <div>
                <Alphabetizer shift={this.state.shift} />
            </div>
        )
    }
}