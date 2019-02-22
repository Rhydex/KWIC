class LineField extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            list: this.props.list || []
        }
    }

    renderLineList = () => {
        let tempList = this.state.list;
        let formattedList = [];
        tempList.forEach(function(ele, index) {
            formattedList.push(<div key={index}>{ele}</div>);
        })
        if(this.state.list) {
            return (
                <div className="well">
                    {formattedList}
                </div>
            )
        }
        return (<div></div>);
    }

    startThingy = () => {
        return;
    }

    render() {
        return (
            <div>
                {this.renderLineList()}
                <CircularShift list={this.state.list} />
            </div>
        )
    }
}