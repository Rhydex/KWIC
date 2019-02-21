class LineField extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            list: this.props.list || []
        }
    }

    renderList = () => {
        let tempList = this.state.list;
        let formattedList = [];
        tempList.forEach(function(ele) {
            formattedList.push(<div>{ele}</div>);
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

    render() {
        return (
            this.renderList()
        )
    }
}