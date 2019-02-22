class Alphabetizer extends React.Component {
    constructor(props) {
        super(props);
        this.state= {
            alph: []
        }
    }
    componentWillReceiveProps(newProps) {
        if (this.props == newProps) {return;}
        this.alphabetizeList(newProps);
    }
    alphabetizeList = (newProps) => {
        let tempList = newProps.shift;
        tempList.sort((a, b) => {
            let compare = a[0].toLowerCase().localeCompare(b[0].toLowerCase());
            let compareTwo = a.toLowerCase().localeCompare(b.toLowerCase());
            if (compareTwo !=0) {
                return compareTwo;
            }
            if (a < b) {
                return 1;
            } else if (a > b) {
                return -1;
            } else {
                return 0;
            }
        });
        this.setState({
            alph: tempList
        });
    }
    render() {
        return(
            <div>
                <OutputField alph={this.state.alph} />
            </div>
            
        )
    }
}