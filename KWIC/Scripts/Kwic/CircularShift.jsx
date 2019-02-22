class CircularShift extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            list: this.props.list || []
        }
    }
    render() {
        return (
            <div>
                <button 
                    className="button"
                    onClick={this.startThingy}
                >
                    Do the thing
                </button>
                <Alphabetizer list={this.state.list} />
            </div>
        )
    }
}